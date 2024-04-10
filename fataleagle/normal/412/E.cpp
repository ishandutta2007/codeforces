#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    int pre=0, temp=0;
    getline(cin, S);
    long long ans=0;
    bool dot=false, valid=false, firstat=false, firstdot=false;
    for(size_t i=0; i<S.length(); i++)
    {
        if(S[i]=='@')
        {
            valid=true;
            firstat=true;
            temp=pre;
            pre=0;
        }
        if(i>0 && S[i-1]!='@' && S[i]=='.' && valid)
            dot=true, firstdot=true;
        if(!firstat && !isalpha(S[i]) && !isdigit(S[i]))
            valid=false;
        if(isalpha(S[i]) && dot)
            ans+=temp;
        if(!firstdot && !isalpha(S[i]))
            dot=false;
        if(pre>0)
        {
            if(isalpha(S[i]) || isdigit(S[i]) || S[i]=='_')
                pre+=isalpha(S[i])?1:0;
            else
                pre=0;
        }
        if(pre==0 && isalpha(S[i]))
            pre=1;
        firstat=false;
        firstdot=false;
    }
    cout<<ans<<endl;
    return 0;
}