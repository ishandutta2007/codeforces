#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
int mod=998244353;
int Size;
int revise[100005];
pair<int,pii> oper[100005];
bool cmp(const pair<int,pii> &p1,const pair<int,pii> &p2){
	if(p1.x/Size==p2.x/Size){
		if(p1.y.x/Size==p2.y.x/Size){
			return p1.y.y<p2.y.y;
		}
		return p1.y.x<p2.y.x;
	}
	return p1.x<p2.x;
}
int Mex[200005];
int cnt[200005];
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	Size=2000;
	int a[100005];
	map<int,int> index;
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		revise[i]=a[i];
		index[a[i]];
	}
	vector<pair<int,pii>> p;
	for(int i = 0;i<q;i++){
		int op,l,r;
		scanf("%d %d %d",&op,&l,&r);
		if(op==1){
			p.pb(mp(i,mp(l,r)));
		}
		else{
			oper[i]=mp(l,mp(r,revise[l]));
			revise[l]=r;
			index[r];
		}
	}
	Mex[0]=1e9;
	int now=0;
	for(auto &it:index){
		it.y=now++;
	}
	for(int i = 1;i<=n;i++){
		a[i]=index[a[i]];
	}
	for(int i = 0;i<q;i++){
		if(oper[i].x!=0){
			oper[i].y.x=index[oper[i].y.x];
			oper[i].y.y=index[oper[i].y.y];
		}
	}
	sort(p.begin(),p.end(),cmp);
	int t=-1,l=1,r=0;
	vector<pii> ans;
	for(auto it:p){
		while(t<it.x){
			t++;
			if(oper[t].x!=0){
				if(oper[t].x>=l&&oper[t].x<=r){
					int pos = oper[t].x;
				//	printf("%d %d %d %d %d\n",cnt[a[pos]],cnt[oper[t].y.x],a[pos],oper[t].y.x,pos);
					Mex[cnt[a[pos]]]--;
					cnt[a[pos]]--;
					Mex[cnt[a[pos]]]++;
					Mex[cnt[oper[t].y.x]]--;
					cnt[oper[t].y.x]++;
					Mex[cnt[oper[t].y.x]]++;
				//	printf("%d %d\n",cnt[a[pos]],cnt[oper[t].y.x]);
				}
				a[oper[t].x]=oper[t].y.x;
			}
		}
		while(t>it.x){
			if(oper[t].x!=0){
				if(oper[t].x>=l&&oper[t].x<=r){
					int pos = oper[t].x;
					Mex[cnt[a[pos]]]--;
					cnt[a[pos]]--;
					Mex[cnt[a[pos]]]++;
					Mex[cnt[oper[t].y.y]]--;
					cnt[oper[t].y.y]++;
					Mex[cnt[oper[t].y.y]]++;
				}
				a[oper[t].x]=oper[t].y.y;
			}
			t--;
		}
		while(l>it.y.x){
			l--;
			Mex[cnt[a[l]]]--;
			cnt[a[l]]++;
			Mex[cnt[a[l]]]++;
		}
		while(r<it.y.y){
			r++;
			Mex[cnt[a[r]]]--;
			cnt[a[r]]++;
			Mex[cnt[a[r]]]++;
		}
		while(l<it.y.x){
			Mex[cnt[a[l]]]--;
			cnt[a[l]]--;
			Mex[cnt[a[l]]]++;
			l++;
		}
		while(r>it.y.y){
			Mex[cnt[a[r]]]--;
			cnt[a[r]]--;
			Mex[cnt[a[r]]]++;
			r--;
		}
		for(int j =0;;j++){
			if(Mex[j]==0){
				ans.pb(mp(it.x,j));
				break;
			}
		}
	}
	sort(ans.begin(),ans.end());
	for(auto it:ans)
	printf("%d\n",it.y);
}