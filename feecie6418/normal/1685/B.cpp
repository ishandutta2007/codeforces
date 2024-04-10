#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int A,B,C,D,n;
char str[200005];
void Solve(){
	cin>>A>>B>>C>>D>>str+1,n=strlen(str+1);
	int cA=0,cB=0;
	for(int i=1;i<=n;i++)cA+=(str[i]=='A'),cB+=(str[i]=='B');
	if(cA!=A+C+D&&cB!=B+C+D)return puts("NO"),void();
	int sum=0;
	vector<int> AB,BA;
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&str[j+1]!=str[j])j++;
		if((j-i+1)&1)sum+=(j-i+1)/2;
		else {
			if(str[i]=='A'){
				int w=(j-i+1)/2;
				AB.push_back(w);
			}
			else {
				int w=(j-i+1)/2;
				BA.push_back(w);
			}
		}
	}
	sort(AB.begin(),AB.end());
	sort(BA.begin(),BA.end());
	for(int i:AB){
		if(C>=i)C-=i;
		else sum+=i-1;
	}
	for(int i:BA){
		if(D>=i)D-=i;
		else sum+=i-1;
	}
	//cout<<C<<' '<<D<<' '<<sum<<'\n';
	if(sum<C+D)puts("NO");
	else puts("YES");
}
int main(){
	int t;
	cin>>t;
	while(t--)Solve(); 
}