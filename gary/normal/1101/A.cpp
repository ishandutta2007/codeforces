#include<bits/stdc++.h>
using namespace std;
int main(){
	int q,ri,li,di;
	cin>>q;
	for(int i=1;i<=q;i++){
		scanf("%d %d %d",&ri,&li,&di);
		if(ri<=di){
			if((li+1)%di==0) cout<<li+1<<endl;
			else cout<<li+1+(di-(li+1)%di)<<endl;
		}
		else{
			cout<<di<<endl;
		}
	}
	return 0;
}