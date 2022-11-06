#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int ansn,l;
int main(){
	std::ios::sync_with_stdio(false);
	cin>>l;
	cin>>s1>>s2;
	for (int i=0;i<l;i++){
		if (i!=l-1){
			if (s1[i]!=s2[i]&&s1[i+1]!=s2[i+1]&&s1[i]==s2[i+1])ansn++,i++;
			else ansn+=abs(s1[i]-s2[i]);
		}else{
			ansn+=(abs(s1[i]-s2[i]));
		}
	}
	cout<<ansn<<endl;
	return 0;
}