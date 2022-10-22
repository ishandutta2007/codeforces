#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;i++)
#define DOR(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;i--)
#define ll long long
#define M 100005
using namespace std;

int n;
char A[M*10];
ll ans;

map<int,ll>cnt;

int main(){
	scanf("%d",&n);
	int tot[26];
	FOR(j,1,n){
		scanf("%s",A);
		int l=strlen(A);
		memset(tot,0,sizeof(tot));
		FOR(i,0,l-1){
			tot[A[i]-'a']^=1;
		}
		int Sta=0;
		FOR(i,0,25){
			if(tot[i])Sta|=1<<i;
		}
		FOR(i,0,25){
			int res=Sta^(1<<i);
			ans+=cnt[res];
		}
		ans+=cnt[Sta];
		cnt[Sta]++;
	}
	cout<<ans<<endl;
	return 0;
}