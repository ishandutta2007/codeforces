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
int n;
string s[100001];
pair<mp,char> a[100001];
pair<string,string> RR[100001];
map<int,int> useless;
int res=0;
bool cmp(pair<mp,char> A,pair<mp,char> B){
	if(A.FIR.FIR!=B.FIR.FIR) return A.FIR.FIR<B.FIR.FIR;
	return A.SEC<B.SEC;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	rb(i,1,n){
		cin>>s[i];
		a[i].FIR.FIR=0;
		a[i].SEC='$';
		a[i].FIR.SEC=i;
		int len=s[i].length();
		rb(j,0,len-1){
			if(s[i][j]=='a'||s[i][j]=='e'||s[i][j]=='i'||s[i][j]=='o'||s[i][j]=='u'){
				a[i].FIR.FIR ++;
				a[i].SEC=s[i][j];
			} 
		}
	}
	rb(i,1,n){
		if(a[i].SEC=='$'){
			cout<<"Oh my God!";
//			cout<<
			return 0;
		}
	}
	sort(a+1,a+1+n,cmp);
	map<int,int> res1;map<pair<int,char>,int >res2;
	a[0].FIR.FIR=INF;
	a[0].SEC='$';
	a[0].FIR.SEC=INF;
	rb(i,1,n){
//		if(a[i].FIR.FIR==a[i-1].FIR.FIR){
			res2[II(a[i].FIR.FIR,a[i].SEC)]++;
			res1[a[i].FIR.FIR]++;
//		}

	}
	map<int,int> ::iterator ite=res1.begin();
	int finalres1=0,finalres2=0;
	for(ite;ite!=res1.end();ite++){
		finalres1+=(ite->SEC)/2;
	}
	map<pair<int,char>,int> :: IT itef;
	for(itef=res2.begin();itef!=res2.end();itef++){
		finalres2+=(itef->SEC)/2;
	}
	finalres1-=finalres2;
	if(finalres2>finalres1){
		while(finalres2>finalres1){
			finalres1++;
			finalres2--;
		}
	}
	cout<<finalres2<<endl;
	if(finalres2==0){
		return 0;
	}
	int resres=finalres2;
	rb(i,1,n){
		if(finalres2==0) break;
		if(!useless[i]&&!useless[i-1])
		if(a[i].FIR.FIR==a[i-1].FIR.FIR){
			if(a[i].SEC==a[i-1].SEC&&a[i].SEC!='$'){
				useless[i-1]=1;
				useless[i]=1;
				RR[finalres2--] =II(s[a[i-1].FIR.SEC],s[a[i].FIR.SEC]);
			}
		}
	}
	int rest=resres;
	int ANS=0;
	vector<pair<mp,char> > FIF;
	int size=0;
	rb(i,1,n){
		if(useless[i]) continue;
		FIF.PB(a[i]);
		size++;
	}
	rb(i,1,size-1){
		if(rest==0) break;
		if(FIF[i].FIR.FIR==FIF[i-1].FIR.FIR){
			cout<<s[FIF[i-1].FIR.SEC]<<" "<<RR[rest].FIR<<endl;
			cout<<s[FIF[i].FIR.SEC]<<" "<<RR[rest--].SEC<<endl;
			ANS++; 
			i++;
		}
	}
	return 0;
}