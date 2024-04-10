#include<stdio.h>
const int MOD=1000000007;
typedef long long LL;
LL add(LL a,LL b){return (a+b)%MOD;
}
LL mul(LL a,LL b){return a*b%MOD;
}
struct Mat{
    LL x[2][2];
    Mat(LL a=0,LL b=0,LL c=0 ,LL d=0){
        x[0][0]=a;x[0][1]=b;x[1][0]=c;x[1][1]=d;
    }
    Mat operator*(const Mat& A)const{
    Mat res;
    for(int i=0;i<2;i++)
    for(int j=0;j<2;j++)
    for(int k=0;k<2;k++)
    res.x[i][j]=add(res.x[i][j],mul(x[i][k],A.x[k][j]));
    return res;}
    Mat operator%(const LL &a){
        for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
        {
            (x[i][j]+=a)%=a;
        }
        return *this;
    }
};
Mat pow(Mat a,int b){
    Mat tmp=a;
    Mat ans(1,0,0,1);
    while(b){
        if(b&1) ans=ans*tmp%MOD;
        tmp =tmp *tmp %MOD;
        b>>=1;
    }
    return ans;
}
main(){
    Mat a(1,1,-1,0);
    int t;
    /*scanf("%d",&t);
    while(t--){*/
        long long int x,y,n;
        scanf("%I64d %I64d %I64d",&x,&y,&n);
        if(n==1)
        printf("%I64d",(x+MOD)%MOD);
        else if(n==2)
        printf("%I64d",(y+MOD)%MOD);
        else{
        Mat ans=pow(a,n-2);
        long long int Ans=(y*ans.x[0][0]+x*ans.x[1][0]+MOD);
        printf("%I64d\n",(Ans%MOD+MOD)%MOD);
        }/*
    }*/
    
}