#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
int f[30];
int Find(int x){
	if(f[x]==x)return x;
	return f[x]=Find(f[x]);
}
int main(){
	int n;
	scanf("%d",&n);
	char c[100005],c1[100005];
	scanf("%s %s",c,c1);
	for(int i =0;i<26;i++){
		f[i]=i;
	}
	vector<pair<char,char> > v;
	for(int i =0;i<n;i++){
		int a=c[i]-'a',b=c1[i]-'a';
		int fa=Find(a),fb=Find(b);
		if(fa!=fb){
			f[fa]=fb;
			v.pb(mp(fa+'a',fb+'a'));
		}
	}
	printf("%d\n",v.size());
	for(auto it:v)
	printf("%c %c\n",it.x,it.y);
}