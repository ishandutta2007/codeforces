#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int Size=2155;
bool cmp(const pair<int,pii> &p,const pair<int,pii> &q){
	if(p.x/Size==q.x/Size){
		if(p.y.x/Size==q.y.x/Size){
			return p.y.y<q.y.y;
		}
		else{
			return p.y.x<q.y.x;
		}
	}
	else{
		return p.x<q.x;
	}
}
int cnt[100005];
int tot[100005];
bool solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[100005];
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	pair<int,pii> p[100005];
	int k[100005];
	int op[100005];
	vector<pair<int,pii> > query;
	for(int i = 1;i<=m;i++){
		//int op;
		scanf("%d",&op[i]);
		if(op[i]==1){
			int l,r;
			scanf("%d %d %d",&l,&r,&k[i]);
			query.pb(mp(i,mp(l,r)));
		}
		else{
			int pos,x;
			scanf("%d %d",&pos,&x);
			p[i]=mp(pos,mp(a[pos],x));
			a[pos]=x;
		}
	}
	for(int i =m;i>=1;i--){
		if(op[i]==2){
			a[p[i].x]=p[i].y.x;
		}
	}
	sort(query.begin(),query.end(),cmp);
	int t=0,l=0,r=0;
	tot[0]=1e5;
	vector<pii> res;
	for(auto it:query){
		while(it.x<t){
			if(op[t]==2){
				int i=t;
				if(p[i].x>=l&&p[i].x<=r){
					tot[cnt[a[p[i].x]]]--;
					cnt[a[p[i].x]]--;
					tot[cnt[a[p[i].x]]]++;
				}
				a[p[i].x]=p[i].y.x;
				if(p[i].x>=l&&p[i].x<=r){
					tot[cnt[a[p[i].x]]]--;
					cnt[a[p[i].x]]++;
					tot[cnt[a[p[i].x]]]++;
				}
			}
			t--;
		}
		while(it.x>t){
			t++;
			if(op[t]==2){
				int i =t;
				if(p[i].x>=l&&p[i].x<=r){
					tot[cnt[a[p[i].x]]]--;
					cnt[a[p[i].x]]--;
					tot[cnt[a[p[i].x]]]++;
				}
				a[p[i].x]=p[i].y.y;
				if(p[i].x>=l&&p[i].x<=r){
					tot[cnt[a[p[i].x]]]--;
					cnt[a[p[i].x]]++;
					tot[cnt[a[p[i].x]]]++;
				}
			}
		}
		while(it.y.x<l){
			l--;
			tot[cnt[a[l]]]--;
			cnt[a[l]]++;
			tot[cnt[a[l]]]++;
		}
		while(it.y.y>r){
			r++;
			tot[cnt[a[r]]]--;
			cnt[a[r]]++;
			tot[cnt[a[r]]]++;
		}
		while(it.y.x>l){
			tot[cnt[a[l]]]--;
			cnt[a[l]]--;
			tot[cnt[a[l]]]++;
			l++;
		}
		while(it.y.y<r){
			tot[cnt[a[r]]]--;
			cnt[a[r]]--;
			tot[cnt[a[r]]]++;
			r--;
		}
		pii p[505];//,num[505];
		int index=0;
		for(int i = 1;i<=1000;i++){
			if(tot[i]){
				//val[index]=i;
				p[index]=mp(i,tot[i]);
				tot[i]=0;
				index++;
			}
		}
		for(int i = 1;i<=1000;i++){
			int x=rand()%(r-l+1)+l;
			if(tot[cnt[a[x]]]){
				//val[index]=cnt[a[x]];
				//num[index]=tot[cnt[a[x]]];
				p[index]=mp(cnt[a[x]],tot[cnt[a[x]]]);
				tot[cnt[a[x]]]=0;
				index++;
			}
		}
		sort(p,p+index);
		int ll=0;
		int tott=0;
		int ans=1e9;
		//printf("%d\n",it.x);
		for(int i = 0;i<index;i++){
			tott+=p[i].y;
		//	printf("%d %d %d %d %d %d\n",val[i],num[i],l,r,it.y.x,it.y.y);
			while(tott-p[ll].y>=k[it.x]){
				tott-=p[ll].y;
				ll++;
			}
			if(tott>=k[it.x]){
				ans=min(ans,p[i].x-p[ll].x);
			}
		}
	//	printf("\n");
		if(ans==1e9)res.pb(mp(it.x,-1));
		else res.pb(mp(it.x,ans));
		for(int i = 0;i<index;i++){
			tot[p[i].x]=p[i].y;
		}
	}
	sort(res.begin(),res.end());
	for(auto it :res)printf("%d\n",it.y);
	return true;
}
int main(){
    int t=1;//00000;
   // scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/