/*
	*#*#*#* Author GaryMr *#*#*#*
	
	long long
	
	dp
	
	 >=0
	
	dpg
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX=0x3f3f3f3f;
char tab[4]={'A','C','T','G'};
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int n,ans=MAX;
	char c[55];
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n-4+1;i++){
		int tmpans=0;
		for(int j=i;j<=i+4-1;j++){
//			cout<<tab[j-i]
//			cout<<tab[j-i]<<" "<<c[j]<<endl;
//			cout<<tmpans; 
			if(tab[j-i]>c[j])
			tmpans+=min(c[j]-'a'+'z'-tab[j-i]+1,abs(tab[j-i]-c[j]));
			else
			tmpans+=min('z'-c[j]+tab[j-i]-'a'+1,abs(tab[j-i]-c[j])); 
//			cout<< " "<<tmpans<<endl;
		}
		ans=min(ans,tmpans);
	} 
	printf("%d\n",ans); 
	return 0;
}