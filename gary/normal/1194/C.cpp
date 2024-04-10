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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int q;
	scanf("%d",&q);
//	int tot=0;
	while(q--){
//		tot++;
		string s,t,p;
		cin>>s>>t>>p;
		if(s.length()==t.length()){
			cout<<((s==t)? "YES":"NO")<<endl;
			continue;
		}
		if(s.length()>t.length()){
			cout<<"NO"<<endl;
			continue;
		}
		int len1=s.length(),len2=t.length(),len3=p.length();
		int l=0;
		int OK=0;
		rb(i,0,len1-1){
//			if(l>=len2) {
//				OK=1;
//				break;
//			}
			while(l<len2&&t[l]!=s[i]){
				l++;
			}
			if(l<len2){
				t[l]='#';
			}
			else{
				OK=1;
			}
			l++;
		}
		if(OK){
			cout<<"NO"<<endl;
			continue;
		}
		map<char,int> count;
		rb(i,0,len3-1){
			count[p[i]]++;
		}
		count['#']=INF;
		rb(i,0,len2-1){
			if(!count[t[i]]){
				OK=1;
				break;
			}
			count[t[i]]--;
		}
		if(OK){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}