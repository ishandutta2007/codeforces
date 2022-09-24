#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7;
int n,ans=1;
set<int> s1,s2,s3;
int main(){
	cin>>n;
	for(int i=1,x;i<=n;i++){
		string op;
		cin>>op>>x;
		if(op=="ADD"){
			if(s1.size()&&x<*--s1.end())s1.insert(x);
			else if(s2.size()&&x>*s2.begin())s2.insert(x);
			else s3.insert(x);
		}
		else {
			if(s3.count(x)){
				ans=2*ans%mod,s3.erase(x);
				while(s3.size()&&(*s3.begin())<x){
					s1.insert(*s3.begin());
					s3.erase(s3.begin());
				}
				while(s3.size()){
					s2.insert(*s3.begin());
					s3.erase(s3.begin());
				}
			}
			else if(s1.count(x)){
				if(x!=*--s1.end())return puts("0"),0;
				s1.erase(x);
				while(s3.size()){
					s2.insert(*s3.begin());
					s3.erase(s3.begin());
				}
			}
			else {
				if(!s2.size()||x!=*s2.begin())return puts("0"),0;
				s2.erase(x);
				while(s3.size()){
					s1.insert(*s3.begin());
					s3.erase(s3.begin());
				}
			}
		}
	}
	cout<<1ll*ans*(s3.size()+1)%mod;
}