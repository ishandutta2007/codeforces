#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define x first
#define y second
#define N 100005
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359	
using namespace std;
int main(){
	string s;
	cin>>s;
	string s1="Bulbasaur";
	int num[256];
	memset(num,0,sizeof(num));
	int ans=0;
	for(int i=0,j=0;i<s.length();i++){
		num[s[i]]++;
	}
	printf("%d\n",min(min(min(num['B'],num['b']),min(num['u']>>1,num['a']>>1)),min(min(num['l'],num['s']),num['r'])));
}