#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
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
string ss;
int JIAA[200005],JIAB[200005],tres[200000]; 
string JIA(string A,string B){
//	cout<<"FUCK"<<endl;
	int len1=A.length();
	int len2=B.length();
	memset(tres,0,sizeof(tres));
	memset(JIAA,0,sizeof(JIAA));
	memset(JIAB,0,sizeof(JIAB));
	rl(i,len1,1){
		JIAA[len1-i+1]=A[i-1]^48;
	}
	rl(i,len2,1){
//		tres[i]=0;
		JIAB[len2-i+1]=B[i-1]^48;
	}
	rb(i,1,max(len1,len2)){
		tres[i]+=JIAA[i]+JIAB[i];
		tres[i+1]+=tres[i]/10;
		tres[i]%=10;
	}
	LL to;
	rb(i,1,150000-2){
		tres[i+1]+=tres[i]/10;
		tres[i]%=10;
		if(tres[i]!=0) to=i;
	}
	ss="";
	rl(i,to,1){
		ss+=char('0'+tres[i]);
	}
	return ss;
}
bool check(string A,string B){
	if(B=="II") return true;
	if(A.length()<B.length()) return true;
	if(A.length()>B.length()) return false;
	return A<B;
}
int main(){
	ios::sync_with_stdio(false);
//	freopen("gary.out","r",stdin);
	int n;
	string s;
	cin>>n>>s;
	string res="II";
	int l,r;
	l=n/2;
	r=l+1;
	string al,bl,ar,br;string tmpres;
	
	rb(i,1,100000){
		al="";
		ar="";
		bl="";
		br="";
		if(l>=2&&l<=n){
			if(s[l-1]!='0'){
			if(max(l-1,n-l+1)<=res.length()||res=="II"){
			rb(i,1,l-1){
				al+=s[i-1];
			}
			rb(i,l,n){
				bl+=s[i-1];
			}
//			if(s[l-1]!='0'){
//				if(max(al.length(),bl.length())<=res.length()||res=="II"){
					 tmpres=JIA(al,bl);
					if(check(tmpres,res)) res=tmpres;
//				}
//			}
				}	
			}

		}
		if(r>=2&&r<=n){
			if(s[r-1]!='0'){
			if(max(r-1,n-r+1)<=res.length()||res=="II"){
			rb(i,1,r-1){
				ar+=s[i-1];
			}
			rb(i,r,n){
				br+=s[i-1];
			}
//			cout<<s<<" " <<r<<" "<<ar<<" "<<br<<endl;
					tmpres=JIA(ar,br);
					if(check(tmpres,res)) res=tmpres;
			}	
			}
//		cout<<tmpres<<" "<<r<<endl;
			
		} 
		l--;
		r++;
	}
//	cout<<res.length()<<endl;
	cout<<res;
	return 0;
}