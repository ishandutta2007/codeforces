import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.AbstractCollection;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author sheep
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    int n, m, s;
    Student[] students;
    int[] bugs;
    Bug[] realBugs;
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        n = in.nextInt();
        m = in.nextInt();
        s = in.nextInt();
        students = new Student[n];
        bugs = new int[m];
        realBugs = new Bug[m];
        for (int i = 0; i < m; ++i) {
            bugs[i] = in.nextInt();
            realBugs[i] = new Bug();
            realBugs[i].level = bugs[i];
            realBugs[i].id = i;
        }
        Arrays.sort(bugs);
        Arrays.sort(realBugs);

        int[] abi, cost;
        abi = new int[n];
        cost = new int[n];
        for (int i = 0; i < n; ++i) {
            abi[i] = in.nextInt();
        }
        for (int i = 0; i < n; ++i) {
            cost[i] = in.nextInt();
        }
        for (int i = 0; i < n; ++i) {
            students[i] = new Student(abi[i], cost[i], i);
        }
        Arrays.sort(students);
        int low = 0, high = 1000000;
        while (low < high) {
            int mid = (low + high) >> 1;
            if (ok(mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        if (low == 1000000) {
            out.println("NO");
            return;
        }
        ok(low);
        out.println("YES");
        for (int i = 0; i < m; ++i) {
            if (i > 0) out.print(" ");
            out.print(who[i] + 1);
        }
        out.println();

    }

    private int[] who;
    private boolean ok(int limit) {
        PriorityQueue<Student> set = new PriorityQueue<Student>();
        int current = 0;
        who = new int[m];
        int rest = s;
        for (int i = m - 1; i >= 0; ) {
            while (current < students.length && students[current].abi >= bugs[i]) {
                set.add(new Student(-students[current].cost, current, -1));
                ++current;
            }
            if (set.isEmpty()) {
                return false;
            }
            Student best = set.poll();
            int index = best.cost;
            if (students[index].cost > rest) return false;
            rest -= students[index].cost;
            for (int j = 0; j < limit && i >= 0; ++j) {
                who[realBugs[i--].id] = students[index].id;
            }
        }
        return true;
    }
    static class Bug implements Comparable<Bug> {
        int level, id;

        public int compareTo(Bug bug) {
            return level - bug.level;
        }
    }
    static class Student implements Comparable<Student> {
        int abi, cost, id;
        Student(int abi, int cost, int id) {
            this.abi = abi;
            this.cost = cost;
            this.id = id;
        }

        public int compareTo(Student student) {
            if (abi != student.abi) return student.abi - abi;
            if (cost != student.cost) return cost - student.cost;
            return id - student.id;
        }
    }
}

class InputReader {
    BufferedReader reader;
    StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (Exception e) {
                throw new UnknownError();
            }
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }