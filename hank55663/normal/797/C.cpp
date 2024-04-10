//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	char c[100005];
	scanf("%s",c);
	vector<char> v;
	int count[26];
	int instk[26];
	MEM(count);
	MEM(instk);
	int find=0;
	for(int i=0;c[i]!=0;i++)
	count[c[i]-'a']++;
	while(count[find]==0)find++;
	for(int i=0;c[i]!=0;i++){
		v.pb(c[i]);
		count[c[i]-'a']--;
		while(count[find]==0)
		find++;
		while(!v.empty()&&v.back()-'a'<=find){
			printf("%c",v.back());
			v.pop_back();
		}
	} 
	while(!v.empty())
	{
		printf("%c",v.back());
		v.pop_back();
	}
}

/*90 110
180 220
270 330
360 440
450 550
540 660
630 770
*/