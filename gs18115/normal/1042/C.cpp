#include<iostream>
#include<vector>
using namespace std;
const int INF=1e9;
vector<int>VM,VZ,VP;
int i,N;
int A[234567];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        if(A[i]<0)
            VM.push_back(i);
        else if(A[i]>0)
            VP.push_back(i);
        else
            VZ.push_back(i);
    }
    if(VM.size()&1)
    {
        int I=VM.back();
        for(i=0;i<VM.size();i++)
            if(A[I]<A[VM[i]])
                I=VM[i];
        VZ.push_back(I);
        for(i=0;i<VM.size();i++)
            if(I!=VM[i])
                VP.push_back(VM[i]);
    }
    else
        for(i=0;i<VM.size();i++)
            VP.push_back(VM[i]);
    if(VP.empty())
        for(i=1;i<N;i++)
            cout<<"1 "<<i<<' '<<i+1<<'\n';
    else if(VZ.empty())
        for(i=1;i<N;i++)
            cout<<"1 "<<i<<' '<<i+1<<'\n';
    else
    {
        for(i=1;i<VZ.size();i++)
            cout<<"1 "<<VZ[i-1]+1<<' '<<VZ[i]+1<<'\n';
        cout<<"2 "<<VZ.back()+1<<endl;
        for(i=1;i<VP.size();i++)
            cout<<"1 "<<VP[i-1]+1<<' '<<VP[i]+1<<'\n';
    }
    cout<<endl;
    return 0;
}