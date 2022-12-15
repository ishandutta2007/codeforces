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
	lint a,b,n;
	cin>>n>>a>>b;
	if(6*n <= a*1LL*b){
		cout<<a*1LL*b<<endl;
		cout<<a<<" "<<b<<endl;
		return 0;
	}
	lint best = ((6*n+a-1)/a) * 1LL * a;
	lint dla = a;
	lint u = sqrt(6*n+10);
		FOR(i,1,u){
			int pb = (6*n+a+i-1)/(a+i);
			if(pb>=b){
				if(best> pb*1LL*(a+i)){
					best = pb*1LL*(a+i);
					dla = a+i;
				}
			}
			else break;
		}
	lint best2 = ((6*n+b-1)/b) * 1LL * b;
	lint dla2 = b;

		FOR(i,1,u){
			int pa = (6*n+b+i-1)/(b+i);
			if(pa>=a){
				if(best2> pa*1LL*(b+i)){
					best2 = pa*1LL*(b+i);
					dla2 = b+i;
				}
			}
			else break;
		}
	
	if(best < best2){
		cout<< best<<endl;
		cout<<dla<<" "<<(6*n+dla-1)/dla<<endl;
	}
	else{
		cout<<best2<<endl;
		cout<<(6*n+dla2-1)/dla2<<" "<<dla2<<endl;
	}
		
		

		
	return 0;
}