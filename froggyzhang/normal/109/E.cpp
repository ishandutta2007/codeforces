#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m;
int k;
int p10[10],p1[10];
bool check(int x){while(x>0){if(x%10!=4&&x%10!=7)return 0; x/=10;} return 1;}
int getw(int x){
    int s=0;
    while(x>0)s+=x%10==4||x%10==7,x/=10;
    return s;
}
int getNextEqual(int x){
    int w=x%10;
    if(w<3||w==5||w==8) return x+1;
    if(w==3||w==6) return x+2;
    if(w==4) return x+3;
    int s=0;
    while(x%10==7)s++,x/=10;
    if(x%10==4) return(x+3)*p10[s]+p1[s] * 4;
    int y=x+1,s1=getw(x),s2=getw(y);
    if(s1==s2)return y*p10[s] +p1[s]*4;
    if(s1-1==s2)return y*p10[s]+p1[s+1] * 4;
    if(s2==s1+1){
        if(s) return y*p10[s]+4*p1[s-1];
        else{
            while(y%10==0)y/=10,s++;
            return(y+1)*p10[s];
        }
    }
    return  -1;
}
int Solve(int a, int l){
    if(l==1) return getNextEqual(a);
    int ans=Solve(a/10,(a+l-1)/10-a/10+1)*10+a%10;
    if(l>=10) return ans;
    int tmp[12];
    for(int i=1;i<=l;i++) tmp[i]=getw(a+i-1);
    for(int k=getNextEqual(a);k<ans;k=getNextEqual(k)){
        bool ok=1;
        for(int i=1;i<=l;i++){
            if(tmp[i]!=getw(k+i-1)){ok=0;break;}
        }
        if(ok) return k;
    }
    return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    int a,l;
    cin>>a>>l;
    p10[0]=1,p1[0]=0;
    for(int i=1;i<=9;i++)p10[i]=10*p10[i-1];
    for(int i=1;i<=9;i++)p1[i]=10*p1[i-1]+1;
    cout<<Solve(a,l)<<endl;
    return 0;
}