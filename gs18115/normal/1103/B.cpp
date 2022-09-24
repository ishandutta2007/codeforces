#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e9;
inline bool query(LL X,LL Y)
{
    cout<<"? "<<X<<' '<<Y<<endl;
    char c;
    cin>>c;
    if(c=='e')
        exit(0);
    return c=='x';
}
inline void answer(LL X)
{
    cout<<"! "<<X<<endl;
    return;
}
string S;
LL i,s,e,mid;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true)
    {
        cin>>S;
        if(S=="mistake")
            exit(0);
        if(S=="end")
            break;
        for(i=1;i<=INF;i<<=1)
            if(!query(i<<1,i))
                break;
        if(i>INF)
        {
            answer(1);
            continue;
        }
        s=i+1;
        e=i<<1;
        while(s<e)
        {
            mid=s+e>>1;
            if(query(e,mid))
                e=mid;
            else
                s=mid+1;
        }
        answer(s);
    }
    return 0;
}