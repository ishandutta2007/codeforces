#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
multiset<int> s;
int a[500005],n;
int main(){
	scanf("%d",&n);
	ll sum=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=1,j;i<=n;i=j+1){
		j=i;
		while(j<n&&a[j+1]==a[i])j++;
		int num=min(j-i+1,i-1);
		int cur=0;
		while(s.size()<min(i-1,j/2))s.insert(0),cur++;
		vector<int> lst;
		for(int k=0;k<num;k++){
			lst.push_back(*s.begin());
			s.erase(s.begin());
		}
		reverse(lst.begin(),lst.end());
		vector<int> t(num,a[i]);
		int r=i-2*((int)s.size()+1);
		for(int k=0;k<num;k++){
			if(lst[k]>a[i]){
				if(r<num&&r>=0)t[r]=2*a[i]-lst[k];
				r--;
			}
			else if(i-1-2*(k+(int)s.size())>=1)lst[k]=a[i];
		}
		for(int k=0;k<num;k++)s.insert(max(t[k],lst[k]));
	}
	ll ans=0;
	for(int i:s)ans+=i;
	cout<<sum-ans;
}