#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

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
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;
#define max_n 100005

string rob(int d, int sum){
	if(sum==0){
		string res="";
		FOR(i,0,d) res+="0";
		return res;
	}
	if(d==0 && sum==0) return "";
	if(d*9<sum) return "";
	string res ="";
	while(sum > 9){
		res="9"+res;
		sum-=9;
		d--;
	}
	if(d==1){
		return string(1,'0'+sum)+res;
	}
	res = string(1,'0'+sum-1)+res;
	d--;
	while(d!=1){
		res = "0"+res;
		d--;
	}
	res = "1"+res;
	return res;
}

string rob2(int d, int sum){
	if(sum==0){
		string res="";
		FOR(i,0,d) res+="0";
		return res;
	}
	if(d==0 && sum==0) return "";
	if(d*9<sum) return "";
	string res ="";
	while(sum > 9){
		res="9"+res;
		sum-=9;
		d--;
	}
	if(d!=0){
		res = string(1,'0'+sum)+res;
		d--;
	}
	while(d!=0){
		res = "0"+res;
		d--;
	}
	return res;
}




int main(){
	IOS;
	//int a,b; cin>>a>>b; cout<<rob(a,b)<<endl;
	int n; cin>>n;
	VI v;
	FOR(i,0,n){
		int b; cin>>b; v.pb(b);
	}
	string last = "0"; int actd = 1;
	FOR(i,0,n){
		if(actd *9 < v[i]){
			actd = (v[i]+8)/9;
			last = rob(actd,v[i]);
			cout<<last<<endl;
		}
		else{
			string nul ="";
			FORD(j,actd-1,0){
				if(nul!="") break;

				int s1 = 0;
				FOR(k,0,j) s1 += (last[k]-'0');
				if(s1 >= v[i]) continue;
				
				FOR(d,last[j]+1,'9'+1){
					if(nul!="") break;
					int mys = s1+d-'0';
					if(v[i]-mys>=0 && v[i]-mys <= 9*(actd-(j+1))){
						nul = last.substr(0,j+1);
						nul[j] = '0'+(d-'0');
						nul+= rob2(actd-(j+1),v[i]-mys);
						last = nul;
					}
				}
			}
			if(nul!=""){
				cout<<last<<endl;
			}
			else{
				actd++;
				last = rob(actd,v[i]);
				cout<<last<<endl;
			}
		}
	}

}