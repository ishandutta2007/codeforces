#include<bits/stdc++.h>
using namespace std;
int n;
string tmps,ans="";
bool Put(){
	if(cin>>tmps )
	{
	
	}else
	 return 1;
	if(tmps=="int"){
		ans+="int";
		return 0;
	}
	if(tmps=="pair"){
		ans+="pair<";
		if(Put()) return 1;
		ans+=",";
		if(Put()) return 1;
		ans+=">";
		return 0;
	}
	return 1;
}
int main(){
//	freopen("in.in","r",stdin);
//	freopen("out.out","w",stdout);
	scanf("%d",&n);
	if(Put()) {
		printf("Error occurred\n");
		return 0;
	}
	if(cin>>tmps){
		printf("Error occurred\n");
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}