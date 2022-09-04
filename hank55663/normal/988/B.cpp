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
#define last Last
using namespace std;
typedef long long LL;
bool cmp(const string &a,const string &b){
	return a.size()<b.size();
}
bool compare(string s1,string s2){
	for(int i=0;i<s2.size();i++){
		int ok=1;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[i+j]){
				ok=0;
				break;
			}
		}
		if(ok)
		return true;
	}
	return false;
}
bool check(vector<string> v){
	for(int i=1;i<v.size();i++){
		if(!compare(v[i-1],v[i]))
			return false;
	}
	return true;
}
int main(){
	int n;
	scanf("%d",&n);
	vector<string> v;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		v.pb(s);
	}
	sort(v.begin(),v.end(),cmp);
	if(check(v)){
		printf("YES\n");
		for(auto it:v)
		cout<<it<<endl;
	}
	else
		printf("NO\n");
}