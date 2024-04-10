#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long LL;
struct point
{
    LL x,y;
    LL p,q;
    point()
    {
        x=y=0;
        p=q=1;
    }
    point(LL X,LL Y)
    {
        x=X;
        y=Y;
        p=q=1;
    }
    point(LL X,LL Y,LL P,LL Q)
    {
        x=X;
        y=Y;
        p=P;
        q=Q;
    }
    bool operator < (point P)
    {
        if(p*P.q!=q*P.p)
            return p*P.q>q*P.p;
        return y==P.y?x<P.x:y<P.y;
    }
}A[123456],B[123456];
stack<LL>S;
LL DISQ(point A,point B)
{
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}
LL ccw(point A,point B,point C)
{
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
LL N,M,i,j;
LL SE,FI,ASZ,BSZ;
LL CHA[123456],CHB[123456];
LL AL[234567],BL[234567],AL2[234567],BL2[234567];
LL pi[234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
    for(i=0;i<N;i++)
        cin>>A[i].x>>A[i].y;
    sort(A,A+N);
    for(i=0;i<N;i++)
    {
        A[i].p=A[i].x-A[0].x;
        A[i].q=A[i].y-A[0].y;
    }
    sort(A+1,A+N);
    S.push(0);
    S.push(1);
    for(i=2;i<N;i++)
    {
        while(S.size()>1)
        {
            SE=S.top();
            S.pop();
            FI=S.top();
            if(ccw(A[FI],A[SE],A[i])>0)
            {
                S.push(SE);
                break;
            }
        }
        S.push(i);
    }
    ASZ=S.size();
    while(!S.empty())
    {
        CHA[S.size()-1]=S.top();
        S.pop();
    }
    for(i=0;i<M;i++)
        cin>>B[i].x>>B[i].y;
    sort(B,B+M);
    for(i=0;i<M;i++)
    {
        B[i].p=B[i].x-B[0].x;
        B[i].q=B[i].y-B[0].y;
    }
    sort(B+1,B+M);
    S.push(0);
    S.push(1);
    for(i=2;i<M;i++)
    {
        while(S.size()>1)
        {
            SE=S.top();
            S.pop();
            FI=S.top();
            if(ccw(B[FI],B[SE],B[i])>0)
            {
                S.push(SE);
                break;
            }
        }
        S.push(i);
    }
    BSZ=S.size();
    while(!S.empty())
    {
        CHB[S.size()-1]=S.top();
        S.pop();
    }
    if(ASZ!=BSZ)
        return cout<<"NO"<<endl,0;
    AL[0]=DISQ(A[CHA[0]],A[CHA[ASZ-1]]);
    BL[0]=DISQ(B[CHB[0]],B[CHB[ASZ-1]]);
    AL2[0]=ccw(A[CHA[ASZ-2]],A[CHA[ASZ-1]],A[CHA[0]]);
    AL2[1]=ccw(A[CHA[ASZ-1]],A[CHA[0]],A[CHA[1]]);
    BL2[0]=ccw(B[CHB[BSZ-2]],B[CHB[BSZ-1]],B[CHB[0]]);
    BL2[1]=ccw(B[CHB[BSZ-1]],B[CHB[0]],B[CHB[1]]);
    for(i=1;i<ASZ;i++)
        AL[i]=DISQ(A[CHA[i]],A[CHA[i-1]]);
    for(i=1;i<BSZ;i++)
        BL[i]=DISQ(B[CHB[i]],B[CHB[i-1]]);
    for(i=2;i<ASZ;i++)
        AL2[i]=ccw(A[CHA[i-2]],A[CHA[i-1]],A[CHA[i]]);
    for(i=2;i<BSZ;i++)
        BL2[i]=ccw(B[CHB[i-2]],B[CHB[i-1]],B[CHB[i]]);
    for(i=0;i<ASZ;i++)
    {
        AL[i+ASZ]=AL[i];
        AL2[i+ASZ]=AL2[i];
    }
    for(i=1;i<BSZ;i++)
    {
        while(j>0&&(BL[i]!=BL[j]||BL2[i]!=BL2[j]))
            j=pi[j-1];
        if(BL[i]==BL[j]&&BL2[i]==BL2[j])
        {
            j++;
            pi[i]=j;
        }
    }
    for(i=0;i<ASZ<<1;i++)
    {
        while(j>0&&(AL[i]!=BL[j]||AL2[i]!=BL2[j]))
            j=pi[j-1];
        if(AL[i]==BL[j]&&AL2[i]==BL2[j])
        {
            if(j==BSZ-1)
                return cout<<"YES"<<endl,0;
            else
                j++;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}