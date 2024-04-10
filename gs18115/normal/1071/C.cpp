#include<iostream>
#include<vector>
using namespace std;
struct P
{
    int x,y,z;
    P():x(0),y(0),z(0){}
    P(int X,int Y,int Z):x(X),y(Y),z(Z){}
};
inline void F(int&x)
{
    x^=1;
    return;
}
vector<P>V;
int N;
int A[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>A[i];
    for(int i=0;i<N-2;i++)
    {
        if(A[i]==1)
        {
            int j;
            for(j=2;j*2<N-i;j++)
                if(A[i+j]==1)
                    break;
            if(i+j*2>=N)
                j=1;
            V.emplace_back(i,i+j,i+j*2);
            F(A[i]);
            F(A[i+j]);
            F(A[i+j*2]);
        }
    }
    if(A[N-2]==1)
    {
        if(N<8)
            return cout<<"NO"<<endl,0;
        V.emplace_back(N-8,N-5,N-2);
        V.emplace_back(N-8,N-7,N-6);
        V.emplace_back(N-7,N-6,N-5);
        F(A[N-2]);
    }
    if(A[N-1]==1)
    {
        if(N<7)
            return cout<<"NO"<<endl,0;
        V.emplace_back(N-7,N-4,N-1);
        V.emplace_back(N-7,N-6,N-5);
        V.emplace_back(N-6,N-5,N-4);
        F(A[N-1]);
    }
    cout<<"YES"<<endl;
    cout<<V.size()<<endl;
    for(int i=0;i<V.size();i++)
        cout<<V[i].x+1<<' '<<V[i].y+1<<' '<<V[i].z+1<<endl;
    return 0;
}