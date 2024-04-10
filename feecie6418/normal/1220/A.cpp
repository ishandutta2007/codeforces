#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int N=510000,inf=1e9,mod=998244353;
int n,cnt[130];
char a[100005];
int main(){
	cin>>n>>a+1;
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	int cntz=cnt['z'],cnt1=cnt['n'];
	while(cnt1--)cout<<"1 ";
	while(cntz--)cout<<"0 ";
}