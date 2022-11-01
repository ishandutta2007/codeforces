#include<bits/stdc++.h>
using namespace std;
int a[100005],temp,k=0,n;
int main(){
    cin>>n;
    stack<int>s;
    for(int i=0;i<n;i++){
        cin>>temp;
        a[temp]=1;
        while(!s.empty() && s.top()<temp){
            a[temp]=max(a[temp],a[s.top()]+1);
            s.pop();
        }
        if(s.size()==0)a[temp]=0;
        s.push(temp);

        k=max(k,a[temp]);
    }
    cout<<k;
    return 0;
}