#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>
#include<cmath>
using namespace std;
#define pb push_back
#define ll long long
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define st first
#define nd second
#define mp make_pair
const int nax=1000123;

int t[nax],s[nax];
map<int,ll> m;
ll res;
char sl[nax];

int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",sl);
	int n=strlen(sl);
	for(int i=0;i<n;++i)t[i+1]=sl[i]-'0';
	for(int i=1;i<=n;++i)s[i]=s[i-1]+t[i];
	for(int i=1;i<=n;++i)
		for(int j=0;j<i;++j){
			m[s[i]-s[j]]++;
			if(s[i]==s[j]&&a==0)res++;
		}
	if(a==0)res=-res*res+res*((ll)n)*((ll)(n+1));
	for(int i=1;i*i<=a;++i)
		if(a%i==0){
			if(i*i==a)res+=m[i]*m[i];
			else res+=2LL*m[i]*m[a/i];
		}
	printf("%I64d",res);
}