import java.io.*;
import java.util.*;


public class A {
    
    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.valueOf(in.readLine());
        
        final int[] x = new int[n];
        final int[] y = new int[n];
        Integer[] p = new Integer[n];
        for (int i = 0; i < n; ++i) {
            String[] tmp = in.readLine().split(" ");
            x[i] = Integer.valueOf(tmp[0]);
            y[i] = Integer.valueOf(tmp[1]);
            p[i] = i;
        }
        
        Arrays.sort(p, new Comparator<Integer>() {
            @Override
            public int compare(final Integer i1, final Integer i2) {
                // TODO Auto-generated method stub
                
                if (x[i1] == x[i2])
                    return y[i1] - y[i2];
                
                return x[i1] - x[i2];
            }
        });
        
        String[] nums = in.readLine().split(" ");
        Map<Integer, TreeSet<Integer>> f = new HashMap<Integer, TreeSet<Integer>>();
        
        for (int i = 0; i < n; ++i) {
            int val = Integer.valueOf(nums[i]);
            if (!f.containsKey(val))
                f.put(val, new TreeSet<Integer>());
            f.get(val).add(i);
        }
        
        Map<String, Integer> minVal = new HashMap<String, Integer>();
        
        int[] ans = new int[n];
        
        for (int i = 0; i < n; ++i) {
            int val = y[p[i]] - x[p[i]];
            if (f.containsKey(val) && !f.get(val).isEmpty()) {
                int mn = -1;
                if (minVal.containsKey((x[p[i]] - 1) + "$" + (y[p[i]])))
                    mn = Math.max(mn, minVal.get((x[p[i]] - 1) + "$" + (y[p[i]])));
                if (minVal.containsKey((x[p[i]]) + "$" + (y[p[i]] - 1)))
                    mn = Math.max(mn, minVal.get((x[p[i]]) + "$" + (y[p[i]] - 1)));
                Integer index = f.get(val).higher(mn);
                if (index == null) {
                    System.out.println("NO");
                    System.exit(0);
                }
                
                minVal.put(x[p[i]] + "$" + y[p[i]], index);
                
                f.get(val).remove(index);
                ans[index] = p[i];
            } else {
                System.out.println("NO");
                System.exit(0);
            }
        }
        
        System.out.println("YES");
        for (int i = 0; i < n; ++i)
            System.out.println(x[ans[i]] + " " + y[ans[i]]);
    }

}