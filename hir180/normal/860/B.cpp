#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
char str[70005][11];
string h[70005][11][11];
int h2[70005][11][11];
map<string,int>S;
int S2[1000005];
int n;
int main(){
	scanf("%d",&n); 
	for(int i=0;i<n;i++) scanf("%s",&str[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<9;j++){
			string st = ""; int st2=0;
			for(int k=j;k<9;k++){
				st.pb(str[i][k]); h[i][j][k]=st; st2 = st2*10+(str[i][k]-'0');
				if(str[i][j]!='0' && k-j+1<=6){ h2[i][j][k]=st2; S2[st2]++; }
				else S[st]++;
			}
		}
	}
	for(int i=0;i<n;i++){
		string ans = "KKKKKKKkkkkkkkkkk";
		for(int j=0;j<9;j++){
			for(int k=j;k<9;k++){
			    int st2 = h2[i][j][k];string st = h[i][j][k];
			    if(st2){
			        S2[st2]--;
			        if(S2[st2]==0 &&ans.size()>st.size()) ans = st;
			    }
				else{
    				S[st]--;
    				if(S[st] == 0 && ans.size()>st.size()){
    					ans = st;
    				}
				}
			}
		}
		for(int j=0;j<9;j++){
			for(int k=j;k<9;k++){
				string st = h[i][j][k]; int st2 = h2[i][j][k];
				if(st2) S2[st2]++; 
				else S[st]++;
			}
		}
		cout<<ans<<endl;
	}
}