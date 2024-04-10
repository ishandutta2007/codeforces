#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int q,a,pw[28];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    pw[0]=1;
    for(int i=1;i<=27;i++) pw[i]=pw[i-1]*2;
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>a;
        for(int i=1;i<=27;i++){
            if(a==pw[i]-1){
                bool fnd=0;
                for(int j=3;j*j<=a;j++){
                    if(a%j==0){
                        cout<<a/j<<"\n";
                        fnd=1;
                        break;
                    }
                }
                if(!fnd){
                    cout<<"1\n";
                }
                break;
            }
            if(pw[i]<=a&&pw[i+1]>a&&a!=pw[i+1]-1){
                cout<<pw[i+1]-1<<"\n";
                break;
            }
        }
    }
    return 0;
}