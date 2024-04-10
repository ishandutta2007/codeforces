#!/usr/bin/env ruby
n = gets.to_i
count = [false] * 5001
gets.split.each { |x| 
    count[x.to_i] = true
}
result = n
1.upto(n) { |x| 
    result -= 1 if count[x]
}
puts result