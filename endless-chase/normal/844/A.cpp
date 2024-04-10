#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<sstream>
using namespace std;
int main()
{
	string s;  
    cin>>s;  
    int k;  
    cin>>k;  
    int a[26]={0};  
    int yeyuyang=s.size();  
    if(k>yeyuyang){  
        cout<<"impossible"<<endl;  
         
    }  else{
	
    for(int i=0;i<yeyuyang;i++){  
        a[s[i]-'a']++;  
    }  
    int ans=0;  
    for(int i=0;i<26;i++){  
        if(a[i]) ans++;  
    }  
    if(k<=ans){
	 cout<<"0";  }
    else{
	cout<<k-ans<<endl; 
}
}
	return 0;
}