# include <iostream>
# include <map>
# include <stdlib.h>
using namespace std;

int main()
{
        int n;
        cin >> n;
        long long arr[101];
        int maxx =0;
        int count=0;
        map <long long, long long> p;
        for(int i=0;i<n;i++)
        {
                char temp;
                cin >> temp;
                cin >> arr[i];
                if (temp == '-')
                        arr[i]*=-1;

                p[abs(arr[i])]+=arr[i];

                if (arr[i]>0)
                        count+=1;
                else
                {
                        count-=1;
                        if(p[abs(arr[i])]<0){
                                maxx+=1;
                                count+=1;
                                p[abs(arr[i])]-=arr[i];
                        }
                }
                if (count > maxx)
                        maxx=count;

        }


        cout << maxx;
        return 0;
}