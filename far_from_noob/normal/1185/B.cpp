#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define fo(i,n) for(int i=0;i<n;i++)




ll n,k,t,m,q,flag=0,countans=0;
int main() {
    cin>>n;
    while(n--){
        string s,s1;
        int temp=0,flag=0;;
        cin>>s>>s1;
        for(int i=0;i<s.size();i++){
            int count=0;

            if(i!=s.size()-1 && s[i]==s[i+1]){
                if(s1[temp]==s[i]){temp++;continue;}
                else {flag=1;
                break;
                }

            }
            else {
                while(s1[temp]==s[i]){
                    //cout<<"fuck";
                    temp++;
                    count++;
                    if(temp==s1.size())break;
                }
                if(count==0){flag=1;break;}
            }


        }
        if(flag || temp!=s1.size())cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}