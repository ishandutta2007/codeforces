#include<bits/stdc++.h>
using namespace std;
string s;
int la,ra,lb,rb,lc,rc;
bool check(int x,int y,int z){
    return x==z||y==z;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>s;
    for (int i=0;i<s.size();i++)
        if (s[i]=='a'){
            if (!la)la=i+1;
            ra=i+1;
        }else
        if (s[i]=='b'){
            if (!lb)lb=i+1;
            rb=i+1;
        }else{
            if (!lc)lc=i+1;
            rc=i+1;
        }
    int all=ra-la+rb-lb+rc-lc+3;
    all==s.size()&&ra<lb&&rb<lc&&la&&lb&&lc&&check(ra-la+1,rb-lb+1,rc-lc+1)?cout<<"YES":cout<<"NO";
    return 0;
}