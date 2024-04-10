#include "bits/stdc++.h"
#define MAXN 100009
#define INF 1000000007
#define mp(x,y) make_pair(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
#define wr cout<<"----------------"<<endl;
#define ppb() pop_back()
#define tr(ii,c) for(__typeof((c).begin()) ii=(c).begin();ii!=(c).end();ii++)
#define ff first
#define ss second
#define my_little_dodge 46
#define debug(x)  cerr<< #x <<" = "<< x<<endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
template<class T>bool umin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>bool umax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
map<string,string>pm;
int main(){
 //   freopen("file.in", "r", stdin);
    string s;
    bool f=0;
    vector<string>v,g,t;
    while(getline(cin,s)){
    	if(int(s[0])==92 and (s.substr(1,5)=="begin" or s.substr(1,3)=="end")){
    		f=1;
    		t.pb(s);
    		continue;
    	}
    	if(f){
			for(int i=0;i<s.size();i++)
				if(int(s[i])==92){
					string tmp;
					for(int j=i+9;s[j]!='}';j++)	
						tmp+=s[j];
					v.pb(tmp);	
					pm[tmp]=s;
				}
    	}
    	else{
    		for(int i=0;i<s.size();i++)
				if(int(s[i])==92){
					string tmp;
					for(int j=i+6;s[j]!='}';j++)	
						tmp+=s[j];
					g.pb(tmp);	
				}
    	}
    }
    if(v==g){
    	puts("Correct");
    }
    else{
    	puts("Incorrect");
    	puts(t[0].c_str());
    	tr(it,g)
    		puts(pm[*it].c_str());
    	puts(t[1].c_str());
	}
	return 0;
}