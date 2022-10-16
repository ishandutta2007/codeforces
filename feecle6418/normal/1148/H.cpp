#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N=200100;
struct data{
	int x1,x2,y1,y2;
	ll sum;
	data(int x1=0,int x2=0,int y1=0,int y2=0,ll sum=0):
		x1(x1),x2(x2),y1(y1),y2(y2),sum(sum){}
};
int a[N],le[N],ri[N],tag[N],lst[N];
vector<data>vec[N];
 
void del(int x,int y){
	if(y>tag[x])vec[x].emplace_back(tag[x],y-1,le[x],ri[x],(vec[x].empty()?0ll:vec[x].back().sum)+(ll)(ri[x]-le[x]+1)*(y-tag[x]));
	tag[x]=0;
}
 
void mdf(int x,int l,int r,int y){
	if(tag[x])del(x,y);else le[x]=l;ri[x]=r;
	tag[x]=y;
}
 
ll query(int K,int l,int r){
	ll ret=0;
	
	if(!vec[K].empty()){
		int L=0,R=vec[K].size(),tL,tR;
		while(L<R){
			int mid=(L+R)/2;
			if(vec[K][mid].x2>=l&&vec[K][mid].y2>=l)R=mid;
			else L=mid+1;
		}
		tL=L;L=-1;R=vec[K].size()-1;
		while(L<R){
			int mid=(L+R+1)/2;
			if(vec[K][mid].x1<=r&&vec[K][mid].y1<=r)L=mid;
			else R=mid-1;
		}
		tR=L;
		if(tL<=tR){
			assert(vec[K][tL].x2>=l&&vec[K][tL].y2>=l&&vec[K][tR].x1<=r&&vec[K][tR].y1<=r);
			ret+=vec[K][tR].sum-(tL?vec[K][tL-1].sum:0);
		
			if(l>vec[K][tL].x1)ret-=(ll)(vec[K][tL].y2-vec[K][tL].y1+1)*(l-vec[K][tL].x1);
		
			if(r<vec[K][tR].x2)ret-=(ll)(vec[K][tR].y2-vec[K][tR].y1+1)*(vec[K][tR].x2-r);
		
			if(vec[K][tL].y1<l){
				L=tL;R=vec[K].size()-1;
				while(L<R){
					int mid=(L+R+1)/2;
					if(vec[K][mid].y1<l)L=mid;
					else R=mid-1;
				}
				ret-=(ll)(l-vec[K][tL].y1)*(min(vec[K][L].x2,r)-max(vec[K][tL].x1,l)+1);
			}
		}
	}
	if(tag[K]){
		int l1=max(l,tag[K]),r1=r,
			l2=max(l,le[K]),r2=min(r,ri[K]);
		if(l1<=r1&&l2<=r2)ret+=(ll)(r1-l1+1)*(r2-l2+1);
	}
	return ret;
}
int n;ll last_ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		int l,r,K;cin>>a[i]>>l>>r>>K;
		a[i]=(a[i]+last_ans)%(n+1);l=(l+last_ans)%i+1;r=(r+last_ans)%i+1;
		if(l>r)swap(l,r);K=(K+last_ans)%(n+1);
		if(tag[a[i]]){
			for(int j=a[i]+1,r=ri[a[i]];;++j)
				if(lst[j]<le[a[i]]){
					mdf(j,le[a[i]],r,i);
					break;
				}else if(lst[j]<r){
					mdf(j,lst[j]+1,r,i);
					r=lst[j];
				}
			del(a[i],i);
		}
		mdf(!a[i],i,i,i);lst[a[i]]=i;
		cout<<(last_ans=query(K,l,r))<<'\n';
	}
	return 0;
}