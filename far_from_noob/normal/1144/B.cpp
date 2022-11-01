#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main() {
    int n;
     cin >>n;
     long long a[n],even[n],odd[n],p=0,q=0;
     for(int i=0;i<n;i++){
         cin >> a[i];
         if(a[i]%2==0){
            even[p]=a[i];
            p++;
         }
         else {
             odd[q]=a[i];
             q++;
         }
     }
     int ans=0;
     if(p>q){
         sort(even,even+p);
         for(int i=0;i<p-q-1;i++){
             ans+=even[i];
         }
     }
     else if(p<q){
         sort(odd,odd+q);
         for(int i=0;i<q-p-1;i++){
             ans+=odd[i];
         }
     }
     cout<< ans;
    return 0;
}