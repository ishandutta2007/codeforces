#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,t;
vector<int> vec;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        vec.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            vec.push_back(x);
        }
        sort(vec.begin(),vec.end(),[](int x,int y) -> bool{return x > y;});
        int num0 = 0;
        while(vec.size() >= 2)
        {
            for(int i=0;i<vec.size()-1;i++)
            {
                vec[i] = vec[i] - vec[i+1];
            }        
            if(num0) num0--;
            else vec.pop_back();
            sort(vec.begin(),vec.end(),[](int x,int y) -> bool{return x > y;});
            while(vec.size() >= 2 && vec.back() == 0) 
            {
                vec.pop_back();
                num0++;
            }
        }
        printf("%d\n",vec[0]);
    }
}