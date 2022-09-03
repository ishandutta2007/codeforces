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
bool solve(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector<LL> v[3];
	int a[200005];
	LL sum=0;
	for(int i = 0;i<n;i++)scanf("%d",&a[i]),sum+=a[i];
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		v[x].pb(a[i]);
	}
	if(sum<m){
		printf("-1\n");
	}
	else{
		int ans=1e9;
		LL pre[200005];
		pre[0]=0;
		for(int i =1;i<3;i++)
		sort(v[i].begin(),v[i].end()),reverse(v[i].begin(),v[i].end());
		for(int i = 1;i<=v[1].size();i++){
			pre[i]=pre[i-1]+v[1][i-1];
		}
		LL sum=0;
		for(int i = 0;i<v[2].size();i++){
			if(sum>=m)ans=min(ans,i*2);
			else{
				int x=lower_bound(pre,pre+v[1].size()+1,m-sum)-pre;
				if(x<=v[1].size()){
					ans=min(ans,i*2+x);
				}
			}
			sum+=v[2][i];
		}
		if(sum>=m)ans=min(ans,(int)v[2].size()*2);
		else{
			int x=lower_bound(pre,pre+v[1].size()+1,m-sum)-pre;
			if(x<=v[1].size()){
				ans=min(ans,(int)v[2].size()*2+x);
			}
		}
		printf("%d\n",ans);

	}
}
int main(){
    int t=1;//00000;
    scanf("%d",&t);
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