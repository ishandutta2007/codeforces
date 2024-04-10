//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
string tmp;
vector<int> a;
bool check(int x){
	if(x==1) return false;
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}
int q=0;
int c[27],k[27];
int main(){
	cin>>tmp;
	if(tmp.length()==1) {
		puts("YES");
		cout<<tmp<<endl;
		return 0;
	}
	int len=tmp.length();
	tmp='$'+tmp;
	a.PB(1);
	rb(i,(len/2)+1,len){
		if(check(i)) a.PB(i);
	}
	rb(i,1,len){
		k[tmp[i]-'a'+1]++;
	}
	rb(i,1,26) c[i]=i;
	rb(i,1,26){
		if(k[i]>k[q]) q=i;
	}
	swap(k[q],k[26]);
	swap(c[q],c[26]);
	if(k[26]<len-a.size()){
		puts("NO");
		return 0;
	}
	puts("YES");
	int w=1;
	rb(i,1,26){
		if(k[i]!=0){
			w=i;
			break;
		}
	}
	int l=0;
	rb(i,1,len){
		if(i==a[l]){
			l++;
			cout<<char('a'+c[w]-1);
			k[w]--;
			if(k[w]==0){
				rb(j,1,26){
					if(k[j]!=0){
						w=j;
						break;
					}
				}
			}
		}
		else{
			cout<<char('a'+c[26]-1);
		}
	}
	return 0;
}