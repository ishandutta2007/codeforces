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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int c[200000+10][27]={0};
int main(){
	int len;
	scanf("%d",&len);
	string s;
	cin>>s;
	rb(i,1,len){
		rb(j,1,26) c[i][j]=c[i-1][j];
		c[i][s[i-1]-'a'+1]++;
	}
	int m;
	scanf("%d",&m);
	while(m--){
		string name;
		cin>>name;
		int hav[27]={0};
		int L=name.length();
		rb(i,1,L){
			hav[name[i-1]-'a'+1]++;
		}
		int res=0;
		rb(i,1,26){
			if(hav[i]==0) continue;
			int ll,rr;
			ll=0,rr=len;
			while(ll<rr){
				int mid=(ll+rr)>>1;
				if(c[mid][i]<hav[i]) {
					ll=mid+1;
				}
				else{
					rr=mid;
				}
			}
			res=max(res,ll);
		} 
		printf("%d\n",res);
	}
	return 0;
}