#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
using namespace std;
typedef long long LL;
LL MOD[5]={1000000007,1000000009,1097774749,1076767633,1001010013};
int main(){
	srand(time(NULL));
	int modnum=rand()%5;
	LL mod = MOD[modnum];
	int n,m;
	scanf("%d %d",&n,&m);
	char c[200005];
	scanf("%s",c+1);
	LL num[26][200005];
	MEM(num);
	LL base[2000005];
	base[0]=1;
	for(int i=1;c[i]!=0;i++){
		for(int j=0;j<26;j++){
			num[j][i]=num[j][i-1]*2%mod;
		}
		num[c[i]-'a'][i]++;
		base[i]=base[i-1]*2%mod;
	}
	while(m--){
		int x,y,len;
		scanf("%d %d %d",&x,&y,&len);
		vector<int> a,b;
		for(int i=0;i<26;i++){
			a.pb(((num[i][x+len-1]-num[i][x-1]*base[len]%mod)%mod+mod)%mod);
			b.pb(((num[i][y+len-1]-num[i][y-1]*base[len]%mod)%mod+mod)%mod);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int ok=1;
		for(int i=0;i<26;i++){
			if(a[i]!=b[i])
			ok=0;
		}
		if(ok)
		printf("YES\n");
		else
		printf("NO\n");
	}
}