#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int main () {
	int n;
	cin>>n;
	int d[n+1][2]={};//kad nebuvvo gym'e nebuvo conteste
	for(int i = 1;i<=n;i++){
	    int x;
	    cin >> x;
	    if(x==0){
	        d[i][0]=min(d[i-1][0],d[i-1][1])+1;
	        d[i][1]=d[i][0];
	    }else if(x==1){
	        d[i][0]=min(d[i-1][0]+1,d[i-1][1]);
	        d[i][1]=min(d[i-1][0],d[i-1][1])+1;
	    }else if(x==2){
	        d[i][0]=min(d[i-1][0],d[i-1][1])+1;
	        d[i][1]=min(d[i-1][1]+1,d[i-1][0]);
	    }else{
	        d[i][0]=min(d[i-1][0]+1,d[i-1][1]);
	        d[i][1]=min(d[i-1][1]+1,d[i-1][0]);
	    }
	}
	cout << min(d[n][0],d[n][1]);

	return 0;
}