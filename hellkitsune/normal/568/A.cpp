#include<bits/stdc++.h>

using namespace std;

int p,q;
long long palnum,prinum;

long long int i,n,pal,ans,j,x;

bool H[2000001];

char str[1000];

int main(){

    H[1]=1;

    for(i=2 ; i<=2000000 ; i++)
        if(!H[i])
            for(j=i*i ; j<=2000000 ; j+=i)
                H[j]=1;


    cin>>p>>q;

    for(i=1 ; i<=2000000 ; i++){
        x=i;
        n=0;
        memset(str,0,sizeof str);
        while(x){
            str[n++]=x%10+'0';
            x/=10;
        }
        pal=1;
        for(j=0 ; j<n/2 ; j++)
            if(str[j]!=str[n-j-1]){
                pal=0;
                break;
            }

        if(pal)
            palnum++;
        
        if(!H[i])
            prinum++;

        if(q*prinum<=p*palnum)
            ans=max(ans,i);
    }

    if(!ans)
        cout<<"Palindromic tree is better than splay tree"<<endl;
    else cout<<ans;

    return 0;
}