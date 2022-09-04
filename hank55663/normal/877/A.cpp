#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int main(){
	string s[5]={"Danil","Olya","Slava","Ann","Nikita"};
	int cnt=0;
	char c[105];
	scanf("%s",c);
	for(int i=0;c[i]!=0;i++){
		for(int j=0;j<5;j++){
			cnt++;
			for(int k=0;k<s[j].size();k++){
				if(s[j][k]!=c[i+k]){
					cnt--;
					break;
				}
			}
		}
	}
	printf("%s\n",cnt==1?"YES":"NO");
}