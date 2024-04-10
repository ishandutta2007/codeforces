#include<bits/stdc++.h>
using namespace std;
#define N 100011
typedef long long ll;
const int mod=1e9+7;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
string s;
int qpow(int a,int b,int mod){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
struct Data{
	int val,len;
	Data(int _val=0,int _len=0){val=_val,len=_len;}
	friend Data operator + (const Data &A,const Data &B){
		return Data((1LL*A.val*qpow(10,B.len,mod)+B.val)%mod,(A.len+B.len)%(mod-1));
	}
	friend Data operator - (const Data &A,const Data &B){
		return Data((A.val+1LL*(mod-B.val)*qpow(10,(A.len-B.len+mod-1)%(mod-1),mod))%mod,(A.len-B.len+mod-1)%(mod-1));
	}
};
string Sub(string a){
	for(int i=0;i<(int)a.length();++i){
		if(a[i]=='0'){
			a[i]='9';
		}
		else{
			--a[i];
			break;
		}
	}
	if(a.back()=='0')a.pop_back();
	return a;
}
const int inv9=qpow(9,mod-2,mod);
const int inv10=qpow(10,mod-2,mod);
const int inv910=10LL*inv9%mod;
inline int S(int n,int _n,int k){
	int H=qpow(10,k,mod);
	int invH=qpow(H,mod-2,mod);
	int v=1LL*H*qpow((H+mod-1)%mod,mod-2,mod)%mod;
	int t=qpow(H,(mod-1-_n-1),mod);
	return 1LL*(1LL*v*(invH-t+mod)%mod+1LL*(mod-n)*t)%mod*v%mod;
}
Data Get(string a){
	if(a.empty())return Data(0,0);
	int num=0,_num=0;
	for(int i=(int)a.length()-1;i>=0;--i){
		num=(10LL*num+a[i]-'0')%mod;
		_num=(10LL*_num+a[i]-'0')%(mod-1);
	}
	Data ans(0,0);
	for(int i=0;i<(int)a.length();++i){
		int l=qpow(10,i,mod),_l=qpow(10,i,mod-1);
		int r,_r;
		if(i==(int)a.length()-1){
			r=num;
			_r=_num;
		}	
		else{
			r=(qpow(10,i+1,mod)+mod-1)%mod;
			_r=(qpow(10,i+1,mod-1)+mod-2)%(mod-1);	
		}
		Data z(0,1LL*(i+1)*(_r-_l+mod)%(mod-1));
		z.val=1LL*(S(r,_r,i+1)-S(l-1,_l-1,i+1)+mod)%mod*qpow(10,1LL*_r*(i+1)%(mod-1),mod)%mod;
		ans=ans+z;
	}
	return ans;
}
Data Cat(string a,string b){
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	Data A=Get(Sub(a)),B=Get(b);
	return B-A;
}
Data get_val(string a){
	int num=0;
	for(int i=0;i<(int)a.length();++i){
		num=(10LL*num+a[i]-'0')%mod;
	}
	return Data(num,(int)a.length());	
}
Data Copy(string a,Data t){
	Data d[10];
	for(int i=1;i<10;++i)d[i]=d[i-1]+t;
	Data ans(0,0);
	for(int i=0;i<(int)a.length();++i){
		Data tmp=ans;
		for(int j=0;j<9;++j)ans=ans+tmp;
		ans=ans+d[a[i]-'0'];
	}
	return ans;
}
string t;
int ban[N];
vector<Data> vec;
int main(){
	cin>>s;
	n=s.length();
	for(int i=0;i<n;++i){
		if(s[i]=='-'){
			int l=i,r=i;
			while(l>0&&isdigit(s[l-1]))--l;
			while(r<n-1&&isdigit(s[r+1]))++r;
			for(int j=l;j<=r;++j)ban[j]=1;
			vec.push_back(Cat(s.substr(l,i-l),s.substr(i+1,r-i)));
		}
	}
	for(int i=0;i<n;++i){
		if(!ban[i]||s[i]=='-')t+=s[i];
	}
	s=t;
	n=s.length();
	int las=-1;
	vector<Data> st;
	vector<string> qwq;
	st.push_back(Data(0,0));
	for(int i=0,k=0;i<n;++i){
		if(s[i]=='('){
			qwq.push_back(s.substr(las+1,i-las-1)),st.push_back(Data(0,0));
		}
		else if(s[i]==')'){
			st.back()=Copy(qwq.back(),st.back());
			qwq.pop_back();
		}
		if(i==n-1||s[i+1]=='+'||s[i+1]==')'){
			if(isdigit(s[i])){
				st.push_back(get_val(s.substr(las+1,i-las)));
			}
			else if(s[i]=='-')st.push_back(vec[k++]);
			auto tmp=st.back();
			st.pop_back();
			st.back()=st.back()+tmp;
		}
		if(!isdigit(s[i]))las=i;
	}
	printf("%d\n",st.back().val);
	return 0;
}