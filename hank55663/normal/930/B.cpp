#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,int>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int m[5005][26][26];
int cnt[26];
int main(){
	char c[5005];
	scanf("%s",c);
	int len=strlen(c);
	for(int i=0;c[i]!=0;i++){
		for(int j=1;j<len;j++){
			m[j][c[i]-'a'][c[(i+j)%len]-'a']++;
		}
		cnt[c[i]-'a']++;
	}
	double ans=0;
	for(int i=0;i<26;i++){
		double Max=0;
		for(int j=1;j<len;j++){
			int a=0,b=0;
			for(int k=0;k<26;k++){
				if(m[j][i][k]==1)
				a++;
				else
				b+=m[j][i][k];
			}
			Max=max(Max,(double)(a)/(a+b));
		}
		//printf("%lf %d\n",Max,cnt[i]);
		ans+=Max*((double)cnt[i]/len);
	}
	printf("%.12lf\n",ans);
}