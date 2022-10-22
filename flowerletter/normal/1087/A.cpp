#include <bits/stdc++.h>
using namespace std;
char s[10010];
int len,cnta;
int main(){
	cin>>s+1;
	len=strlen(s+1);
	//if(len%2==0){
		int mid=1+len>>1;
		int cnt=0;
		int l=mid-1,r=mid+1;
		cout<<s[mid];cnt++;
		while(cnt<len){
		    cnt++;
			if(cnt%2==0) cout<<s[r++];
			else cout<<s[l--];
		}
	//}
	return 0;
}