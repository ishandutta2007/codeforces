#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int a;

int ask(int x, int y)
{
    cout<<"? "<<x<<" "<<y<<endl;
    char c; cin>>c;
    return (c=='x'?1:2);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    string s;
    while(cin>>s){
        if(s[0]=='m' || s[0]=='e'){
            break;
        }
        int k=0;
        if(ask(0,1)==1){
            cout<<"! "<<1<<endl;
            continue;
        }
        while(k<30){
            int tp=ask(1<<k+1, 1<<k);
            if(tp==2)break;
            k+=1;
        }
        int g=0;
        for(int i=29; i>=0; i--){
            if((1ll<<k)+(1ll<<i)+g>=(1ll<<k+1))continue;
            int tp=ask(1<<k+1,(1<<k)+g+(1<<i));
            if(tp==2)g+=1<<i;
        }
        cout<<"! "<<(1<<k)+g+1<<endl;
    }
}