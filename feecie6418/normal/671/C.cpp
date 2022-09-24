#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,a[200005],tag[800005],fir[200005],premx[200005];
int mx[800005],mi[800005],sufmx[800005];
ll s[800005],ans=0,len[800005];
vector<int> d[200005];
vector<pr> to[200005];
void Tag(int p,int z){
	tag[p]=z,mx[p]=mi[p]=z,s[p]=len[p]*z;
}
void Pushdown(int p){
	if(tag[p]){
		Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=0;
	}
}
void Build(int p,int l,int r){
	len[p]=r-l+1;
	if(l==r)return mx[p]=mi[p]=s[p]=premx[l-1],void();
	int mid=(l+r)>>1;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	mx[p]=max(mx[p*2],mx[p*2+1]);
	mi[p]=min(mi[p*2],mi[p*2+1]);
	s[p]=s[p*2]+s[p*2+1];
	
}
void Makemx(int p,int l,int r,int x,int y,int z){
	if(x<=l&&r<=y){
		if(mi[p]>=z)return ;
		if(mx[p]<=z)return Tag(p,z);
	}
	int mid=(l+r)/2;
	Pushdown(p);
	if(x<=mid)Makemx(p*2,l,mid,x,y,z);
	if(mid<y)Makemx(p*2+1,mid+1,r,x,y,z);
	mx[p]=max(mx[p*2],mx[p*2+1]);
	mi[p]=min(mi[p*2],mi[p*2+1]);
	s[p]=s[p*2]+s[p*2+1];
}
ll GetS(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return s[p];
	Pushdown(p);
	int mid=(l+r)/2;
	if(x>mid)return GetS(p*2+1,mid+1,r,x,y);
	if(y<=mid)return GetS(p*2,l,mid,x,y);
	return GetS(p*2,l,mid,x,y)+GetS(p*2+1,mid+1,r,x,y);
}
int main(){
	cin>>n;
	for(int i=1;i<=200000;i++){
		for(int j=i;j<=200000;j+=i){
			d[j].push_back(i); 
		}
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j:d[a[i]]){
			if(fir[j])to[i].push_back(pr(fir[j],j)),premx[i]=max(premx[i],j);
			else fir[j]=i;
		}
		premx[i]=max(premx[i],premx[i-1]);
	}
	memset(fir,0,sizeof(fir));
	for(int i=n;i>=1;i--){
		for(int j:d[a[i]]){
			if(fir[j])sufmx[i]=max(sufmx[i],j);
			else fir[j]=i;
		}
		sufmx[i]=max(sufmx[i],sufmx[i+1]);
	}
	Build(1,1,n);
	for(int i=n;i>=1;i--){
		ans+=GetS(1,1,n,1,i);
		if(i==1)break;
		Makemx(1,1,n,1,i-1,sufmx[i]);
		for(auto k:to[i]){
			int j=k.first,v=k.second;
			if(j+1<=i-1)Makemx(1,1,n,j+1,i-1,v);
		}
	}
	cout<<ans;
}