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
	int n,e=0,o=0,wangyihan_yeyuyanghuruiyanzhaoyouranchenkaiweilvpinjiechensitong,wangyihan_yeyuyanghuruiyanzhaoyouranchenkaiweilvpinjiechensitong2,a[110];  
   cin>>n;  
   wangyihan_yeyuyanghuruiyanzhaoyouranchenkaiweilvpinjiechensitong=0;  
   wangyihan_yeyuyanghuruiyanzhaoyouranchenkaiweilvpinjiechensitong2=0;  
    
   for(int i=0;i<n;i++)  
    {  
       cin>>a[i];  
       if(a[i]%2==1)  
       {  
           e++;  
           if(!wangyihan_yeyuyanghuruiyanzhaoyouranchenkaiweilvpinjiechensitong)  
           {  
                wangyihan_yeyuyanghuruiyanzhaoyouranchenkaiweilvpinjiechensitong=i+1;  
           }  
       }  
       else  
       {  
           o++;  
           if(!wangyihan_yeyuyanghuruiyanzhaoyouranchenkaiweilvpinjiechensitong2) wangyihan_yeyuyanghuruiyanzhaoyouranchenkaiweilvpinjiechensitong2=i+1;  
       }  
    }  
if(e==1){

cout<<wangyihan_yeyuyanghuruiyanzhaoyouranchenkaiweilvpinjiechensitong;
}
   else{
   cout<<wangyihan_yeyuyanghuruiyanzhaoyouranchenkaiweilvpinjiechensitong2;  
}

	return 0;
}