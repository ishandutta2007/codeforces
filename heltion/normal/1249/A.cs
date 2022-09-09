using System;
namespace H{
    class H{
        static void Main(string[] args)
        {
            for(int q = int.Parse(Console.ReadLine()); q > 0; q -= 1){
                int n = int.Parse(Console.ReadLine());
                int []a = Array.ConvertAll(Console.ReadLine().Split(), x => int.Parse(x));
                Array.Sort(a);
                int ans = 1;
                for(int i = 0; i + 1 < n; i += 1) if(a[i] + 1 == a[i + 1]) ans = 2;
                Console.WriteLine(ans);
            }
        }
    }
}