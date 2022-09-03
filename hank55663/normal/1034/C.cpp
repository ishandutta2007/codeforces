#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
LL Size[1000005];
int a[1000005];
vector<int> v[1000005];
LL dfs(int x,int f){
	Size[x]=a[x];
	for(auto it:v[x]){
		if(it!=f){
			Size[x]+=dfs(it,x);
		}
	}
	return Size[x];
}
bool check(LL a,int n){
	int need=Size[1]/a;
	if(need>n)
	return false;
	for(int i=1;i<=n;i++){
		if(Size[i]%a==0)
		need--;
	}
	return need==0;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		v[x].pb(i);
	}
	dfs(1,0);
    map<LL,int> cnt;
    for(int i=1;i<=n;i++){
      //  printf("%d %d\n",Size[i],__gcd(Size[1],Size[i]));
        cnt[__gcd(Size[1],Size[i])]++;
    }
    for(LL i=1;i*i<=Size[1];i++){
        if(Size[1]%i==0){
            cnt[i];cnt[Size[1]/i];
        }
    }
	vector<LL> prime;
    LL k=Size[1];
	for(LL i=2;i*i<=k;i++){
		if(k%i==0){
            prime.pb(i);
            while(k%i==0){
                k/=i;
            }
        }
	}
    if(k!=1)
    prime.pb(k);
    for(auto it:prime){
        for(auto it2=cnt.rbegin();it2!=cnt.rend();it2++){
            if(it2->x%it==0){
                cnt[it2->x/it]+=it2->y;
            }
        }
    }
    vector<LL> v;
    for(auto it:cnt){
   //     printf("%d %d\n",it.x,it.y);
        if(Size[1]/it.x==it.y){
            v.pb(it.x);
        }
    }
	sort(v.begin(),v.end());
	vector<int> dp;
	int mod=1e9+7;
	dp.pb(1);
	for(int i=1;i<v.size();i++){
		int sum=1;
		for(int j=0;j<i;j++){
			if(v[i]%v[j]==0){
				sum+=dp[j];
				sum%=mod;
			}
		}
		dp.pb(sum);
	}
	printf("%d\n",dp.back());
}