#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
	int n, t;
	cin >>n>> t ;
	int a[n],ans[n];
	for(int i=0;i<n;i++){
	    cin >> a[i];
	    ans[i]=0;
	}
	int count=0,j;
	for(j=0;j<n;j++){
	    count+=a[j];
	    if(count<=t)
        ans[0]++;
        else break;
	}        
	for(int i=1;i<n;i++){
	    if(ans[i-1]!=0){
	    count=count-a[i-1]-a[j];
	    ans[i]=ans[i-1]-1;
	    
	    for(;j<n;j++){
	        count+=a[j];
	        if(count<=t)
            ans[i]++;
            else break;
	    }
	    }
	    else {
	        count=count-a[j];
	        for(j=j+1;j<n;j++){
	        count+=a[j];
	        if(count<=t)
            ans[i]++;
            else break;
	    }
	    }
	}
	
	/*for(int i=0;i<n;i++){
	    ans[i]=0;
	    int count=0;
	    for(int j=i;j<n;j++){
	        count+=a[j];
	        if(count<=t)
	        ans[i]++;
	        else break;
	    }
	}*/
	//cout<<ans[0]<<ans[1];
	sort(ans,ans+n);
	cout<<ans[n-1]<<endl;
	
	
	return 0;
}