#!/usr/bin/env ruby
result, length, lastChar= 0, 0, 'G'
gets.each_byte { |c|
    break if c == 10
    if c == lastChar
        if length < 5
            length += 1
        elsif
            result += 1
            length = 1
        end
    elsif
        result += 1
        length = 1
        lastChar = c
    end
}
puts result