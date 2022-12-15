#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())
#define all(x) x.begn(),x.end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define IOS ios_base::sync_with_stdio(0)


#define max_n 2000005


using namespace std;


int main(){
	IOS;
	make2(n,p);
	char s[1005];
	scanf("%s",s);
	
	bool flaga = false;

	if(p==1){
		cout<<"NO"<<endl;
		return 0;
	}

	if(p==2){
		if(n==1 && s[0]=='a') cout<<"b"<<endl;
		if(n==1 && s[0]=='b') cout<<"NO"<<endl;
		if(n==2 && s[0]=='a') cout<<"ba"<<endl;
		if(n==2 && s[0]=='b') cout<<"NO"<<endl;
		return 0;
	}

	

	FORD(i,n-1,0){		
		while(s[i]-'a'<p-1){
			s[i]++;
			if(i>1 && s[i]==s[i-2]) continue;
			if(i>0 && s[i]==s[i-1]) continue;
			FOR(j,i+1,n){
				int zakaz[]={0,0,0};
				FOR(k,1,3){
					if(j-k>=0 && (s[j-k]-'a')<3){
						zakaz[s[j-k]-'a']=1;
					}
				}
				int u=0; 
				while(zakaz[u]==1) u++;
				s[j]='a'+u;
			}
			cout<<s<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
	




	return 0;
}