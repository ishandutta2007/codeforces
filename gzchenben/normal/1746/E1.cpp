#include<cstdio>
#include<vector>
using namespace std;
int n;
vector<int> vec;

char s[10];
bool Ask(int L,int R)
{
    printf("? %d",R-L+1);
    for(int i=L;i<=R;i++)
        printf(" %d",vec[i]);
    printf("\n");
    fflush(stdout);
    scanf("%s",s+1);
    if(s[1] == 'Y') return true;
    else return false;
}

int check(int M1,int M2)
{
    bool r1 = Ask(0,M1-1);
    if(!r1)
        r1 = Ask(0,M1-1);

    if(!r1)
        return 1;
    else
    {
        bool r2 = Ask(M1,M2-1);
        if(r2) return 3;
        else return 2;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        vec.push_back(i);
    while(vec.size() >= 3)
    {
        int Mid1 = vec.size()/3;
        int Mid2 = vec.size()*2/3;
        int cur = check(Mid1,Mid2);
        vector<int> tmp;
        if(cur == 1)
        {
            for(int i=0;i<vec.size();i++)
                if(i >= Mid1) tmp.push_back(vec[i]);
        }
        if(cur == 2)
        {
            for(int i=0;i<vec.size();i++)
                if(i < Mid1 || i >= Mid2) tmp.push_back(vec[i]);
        }
        if(cur == 3)
        {
            for(int i=0;i<vec.size();i++)
                if(i < Mid2) tmp.push_back(vec[i]);
        }
        vec = tmp;
    }
    for(auto &p : vec)
    {
        printf("! %d\n",p);
        fflush(stdout);
        scanf("%s",s+1);
        if(s[2] == ')') return 0;
    }
}