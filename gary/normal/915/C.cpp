/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string a,b;
vector<int > A,B;
bool cmp(int AA,int BB){
	return AA>BB;
}
int cnt[10];
int main(){
	cin>>a>>b;
	rep(i,a.length()) A.PB(a[i]-'0'),cnt[int(a[i]-'0')]++;
	rep(i,b.length()) B.PB(b[i]-'0');
	if(a.length()<b.length()){
		sort(ALL(A),cmp);
		rep(i,a.length()) cout<<A[i];
		return 0;
	}
	rep(i,a.length()){
		rl(j,9,0){
			if(cnt[j]){
				if(j==B[i]){
				cnt[j]--;
				int St=i+1;
				int OK=1;
				rb(k,0,9){	if(OK==2||OK==0) break;rep(tmp,cnt[k]){
				if(k<B[St]){
					OK=2;
					break;
				}
				else{ if(k>B[St]) {OK=0;break;}St++;
				}	
				}			}
				
				
				if(OK){
					cout<<j;
					break;
				} 
				else cnt[j]++; 
			}
			if(j<B[i]){
				cout<<j;
				cnt[j]--;
				rl(k,9,0)
				rep(tmp,cnt[k]) cout<<k; 
				return 0;
			}
			}
			
		}
	}
	return 0;
}